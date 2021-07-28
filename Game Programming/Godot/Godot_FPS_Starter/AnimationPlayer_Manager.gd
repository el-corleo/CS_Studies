extends AnimationPlayer

var states = {
	"Idle_unarmed":["Knife_equip", "Pistol_equip", "Rifle_equip", "Idle_unarmed"],

	"Pistol_equip":["Pistol_idle"],
	"Pistol_fire":["Pistol_idle"],
	"Pistol_idle":["Pistol_fire", "Pistol_reload", "Pistol_unequip", "Pistol_idle"],
	"Pistol_reload":["Pistol_idle"],
	"Pistol_unequip":["Idle_unarmed"],

	"Rifle_equip":["Rifle_idle"],
	"Rifle_fire":["Rifle_idle"],
	"Rifle_idle":["Rifle_fire", "Rifle_reload", "Rifle_unequip", "Rifle_idle"],
	"Rifle_reload":["Rifle_idle"],
	"Rifle_unequip":["Idle_unarmed"],

	"Knife_equip":["Knife_idle"],
	"Knife_fire":["Knife_idle"],
	"Knife_idle":["Knife_fire", "Knife_unequip", "Knife_idle"],
	"Knife_unequip":["Idle_unarmed"],
}

var animation_speeds = {
	"Idle_unarmed":1,

	"Pistol_equip":1.4,
	"Pistol_fire":1.8,
	"Pistol_idle":1,
	"Pistol_reload":1,
	"Pistol_unequip":1.4,

	"Rifle_equip":2,
	"Rifle_fire":6,
	"Rifle_idle":1,
	"Rifle_reload":1.45,
	"Rifle_unequip":2,

	"Knife_equip":1,
	"Knife_fire":2,
	"Knife_idle":1,
	"Knife_unequip":1,
}

var current_state = null
var callback_function = null

func _ready():
	set_animation("Idle_unarmed")
	connect("animation_finished", self, "animation_ended")

func set_animation(anim_name):
	if anim_name == current_state:
		print("AnimationPlayer_Manager.gd -- WARNING: animation is already ", anim_name)
		return true
		
	if has_animation(anim_name):
		if current_state != null:
			var possible_animations = states[current_state]
			if anim_name in possible_animations:
				current_state = anim_name
				play(anim_name, -1, animation_speeds[anim_name])
				return true
			else:
				print("AnimationPlayer_Manager.gd -- WARNING: cannot change to ", anim_name, " from ", current_state)
				return false
		else:
			current_state = anim_name
			play(anim_name, -1, animation_speeds[anim_name])
			return true
	
	return false

func animation_ended(anim_name):
	match current_state:
		# UNARMED transitions
		"Idle_unarmed":
			pass
		# KNIFE transitions
		"Knife_equip":
			set_animation("Knife_idle")
		"Knife_idle":
			pass
		"Knife_fire":
			set_animation("Knife_idle")
		"Knife_unequip":
			set_animation("Idle_unarmed")
		# PISTOL transitions
		"Pistol_equip":
			set_animation("Pistol_idle")
		"Pistol_idle":
			pass
		"Pistol_fire":
			set_animation("Pistol_idle")
		"Pistol_unequip":
			set_animation("Idle_unarmed")
		"Pistol_reload":
			set_animation("Pistol_idle")
		# RIFLE transitions
		"Rifle_equip":
			set_animation("Rifle_idle")
		"Rifle_idle":
			pass
		"Rifle_fire":
			set_animation("Rifle_idle")
		"Rifle_unequip":
			set_animation("Idle_unarmed")
		"Rifle_reload":
			set_animation("Rifle_idle")
	
func animation_callback():
	if callback_function == null:
		print("AnimationPlayer_Manager.gd -- WARNING: No callback function for the animation to call!")
	else:
		callback_function.call_func()
