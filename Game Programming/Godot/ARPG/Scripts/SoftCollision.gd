extends Area2D

func get_push_vector():
	var overlap_areas = get_overlapping_areas()
	var push_vector = Vector2.ZERO
	if overlap_areas.size() > 0:
		var overlap = overlap_areas[0]
		push_vector = overlap.global_position.direction_to(global_position).normalized()
	return push_vector
