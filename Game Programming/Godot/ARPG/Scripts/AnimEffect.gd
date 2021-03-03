extends AnimatedSprite


func _ready():
	connect("animation_finished",self,"_on_anim_done")
	play("animate")


func _on_anim_done():
	queue_free()
