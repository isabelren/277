#version 150
// ^ Change this to version 130 if you have compatibility issues

uniform mat4 u_Model;
uniform mat4 u_ViewProj;

//associate vs_pos with a single set of 4 floats in the bugger
//the single vec4 is what we will store in vs_Pos
//keyword in gives each execution thread a different vertex
in vec4 vs_Pos;
in vec4 vs_Col;

//out variables- in variables to be passed down the pipeline
out vec4 fs_Col;

void main()
{
    fs_Col = vs_Col;

    //model passed in is multiplied by vs_Pos
    vec4 modelposition = u_Model * vs_Pos;

    //built-in things to pass down the pipeline
    //projecting from 3d space to 2d space
    //passing 2D space down the pipeline
    //transforming from 3d world space to 2d space on pixel screens
    gl_Position = u_ViewProj * modelposition;

    //viewProj is viewing prospective geometry

}
