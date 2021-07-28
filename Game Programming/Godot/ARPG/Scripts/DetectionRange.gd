extends Area2D

var player = null


func player_visible():
	return player != null

func _on_DetectionRange_body_entered(body):
	player = body


func _on_DetectionRange_body_exited(body):
	player = null
