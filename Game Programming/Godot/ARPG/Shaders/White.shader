shader_type canvas_item;

uniform bool active = true;

void fragment() 
{
	vec4 prev_color = texture(TEXTURE, UV);
	vec4 white = vec4(1.0,1.0,1.0,prev_color.a);
	if (active)	COLOR = white;
	else		COLOR = prev_color;
}