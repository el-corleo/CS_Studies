extends Node2D

const GrassEffect = preload("res://Levels/GrassDestroyed.tscn")

func create_effect():
	var grass_effect = GrassEffect.instance()
	get_parent().add_child(grass_effect)
	grass_effect.global_position = global_position


func _on_HurtBox_area_entered(area):
	create_effect()
	queue_free()
