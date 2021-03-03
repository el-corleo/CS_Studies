extends KinematicBody2D

const ACCELERATION = 300
const MAX_SPEED = 50
const FRICTION = 200
const KNOCKBACK_FORCE = 100

enum STATE {
	IDLE,
	WANDER,
	CHASE
}

var state = STATE.WANDER

const BatDestroyed = preload("res://Characters/BatDestroyed.tscn");

var velocity = Vector2.ZERO
var knockback = Vector2.ZERO

onready var sprite = $Body
onready var stats = $Stats
onready var detection_range = $DetectionRange
onready var hurtBox = $HurtBox
onready var softCollision = $SoftCollision
onready var wanderController = $WanderController

func _physics_process(delta):
	knockback = knockback.move_toward(Vector2.ZERO, FRICTION * delta)
	knockback = move_and_slide(knockback)
	
	match state:
		STATE.IDLE:
			velocity = velocity.move_toward(Vector2.ZERO, FRICTION * delta)
			seek_player()
			if wanderController.get_time_left() == 0:
				pick_rand_state([STATE.IDLE, STATE.WANDER])
		
		STATE.WANDER:
			seek_player()
			if wanderController.get_time_left() == 0:
				pick_rand_state([STATE.IDLE, STATE.WANDER])
			accelerate_toward(wanderController.target_position, delta)
			
		STATE.CHASE:
			var player = detection_range.player
			if player != null:
				accelerate_toward(player.global_position, delta)
			else:
				state = STATE.WANDER
	
	#prevents bats from overlapping
	velocity += softCollision.get_push_vector()
	
	velocity = move_and_slide(velocity)	


func accelerate_toward(point, delta):
	var direction = global_position.direction_to(point)
	velocity = velocity.move_toward(direction * MAX_SPEED, ACCELERATION * delta)
	sprite.flip_h = velocity.x < 0


func seek_player():
	if detection_range.player_visible():
		state = STATE.CHASE


func pick_rand_state(state_list):
	state_list.shuffle()
	state = state_list.pop_front()
	wanderController.start_wander_timer(rand_range(1,2))


func _on_HurtBox_area_entered(area):
	stats.set_health(stats.health - area.damage)
	knockback = area.knockback_vector * KNOCKBACK_FORCE
	hurtBox.create_hit_effect()


func _on_Stats_death():
	var batDestroyed = BatDestroyed.instance()
	get_parent().add_child(batDestroyed)
	batDestroyed.global_position = global_position
	queue_free()
