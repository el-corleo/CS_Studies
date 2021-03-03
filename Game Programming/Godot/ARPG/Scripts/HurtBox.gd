extends Area2D

const HitEffect = preload("res://Characters/BatHitEffect.tscn")
export var offset = Vector2(0,0)
var invincible = false setget set_invincible, get_invincible

onready var timer = $Timer
onready var collision_shape = $CollisionShape2D

signal invincible_mode_on
signal invincible_mode_off

func set_invincible(status):
	invincible = status
	if invincible:
		emit_signal("invincible_mode_on")
	else:
		emit_signal("invincible_mode_off")


func get_invincible():
	return invincible

func start_i_frames(duration):
	self.invincible = true
	timer.start(duration)


func create_hit_effect():
	var effect = HitEffect.instance()
	var main = get_tree().current_scene
	main.add_child(effect)
	effect.global_position = global_position + offset


func _on_HurtBox_area_entered(area):
	if not invincible:
		create_hit_effect()


func _on_Timer_timeout():
	self.invincible = false


func _on_HurtBox_invincible_mode_on():
	collision_shape.set_deferred("disabled", true)


func _on_HurtBox_invincible_mode_off():
	collision_shape.set_deferred("disabled", false)
