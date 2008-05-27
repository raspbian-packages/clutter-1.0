/* Inputs from the vertex shader */
varying vec4 frag_color;
varying vec2 tex_coord;

/* Texturing options */
uniform bool       texture_2d_enabled;
uniform sampler2D  texture_unit;
uniform bool       alpha_only;

void
main (void)
{
  if (texture_2d_enabled)
    {
      if (alpha_only)
	{
	  /* If the texture only has an alpha channel (eg, with the
	     textures from the pango renderer) then the RGB components
	     will be black. We want to use the RGB from the current
	     color in that case */
	  gl_FragColor = frag_color;
	  gl_FragColor.a *= texture2D (texture_unit, tex_coord).a;
	}
      else
	gl_FragColor = frag_color * texture2D (texture_unit, tex_coord);
    }
  else
    gl_FragColor = frag_color;
}
