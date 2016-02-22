#version 150

uniform mat4 bind_matrices[100]; //bindMatrix of each joint
uniform mat4 joint_transforms[100]; //current overall transforms of each joint
in ivec2 influencer_IDs; //first is first influence, second is second influence
in vec2 influencer_weights; //two weights
uniform vec4 u_Eye;

uniform mat4 u_Model;       //The matrix that defines the transformation of the
                            //object we're rendering. In this assignment,
                            //this will be the result of traversing your scene graph.

uniform mat4 u_ModelInvTr;  //The inverse transpose of the model matrix.
                            //This allows us to transform the object's normals properly
                            //if the object has been non-uniformly scaled.

uniform mat4 u_ViewProj;    //The matrix that defines the camera's transformation.
                            //We've written a static matrix for you to use for HW2,
                            //but in HW3 you'll have to generate one yourself

in vec4 vs_Pos;//---------->The array of vertex positions passed to the shader

in vec4 vs_Nor;//---------->The array of vertex normals passed to the shader

in vec4 vs_Col;//---------->The array of vertex colors passed to the shader.

out vec4 fs_Nor;//--------->The array of normals that has been transformed by u_ModelInvTr. This is implicitly passed to the fragment shader.
out vec4 fs_LightVec;//---->The direction in which our virtual light lies, relative to each vertex. This is implicitly passed to the fragment shader.
out vec4 fs_Col;//--------->The color of each vertex. This is implicitly passed to the fragment shader.

const vec4 lightPos = vec4(5, 5, 3, 1); //The position of our virtual light, which is used to compute the shading of
                                        //the geometry in the fragment shader.

void main()
{
    fs_Col = vs_Col;//                          Pass the vertex color positions to the fragment shader
    fs_Nor = u_ModelInvTr * vs_Nor;//           Transform the geometry's normals

    vec4 modelposition = u_Model * vs_Pos;//    Temporarily store the transformed vertex positions for use below

    //for each item at index i in influencer ID's (gives us joint by going through influencer weights)
    //get weight of the same joint at index i (gives us weihgt by going through influencer weights)
    //get overall transform by getting value at index i, in the joint transforms matrix
    //get bind matrix bind_matrices[influencer_IDs[i]] * modelposition

     //vec4 transformedposition = modelposition;
    //how to get influencer_IDs.size()??
    /*for (int i = 0; i < 2; i++) {
        int idx = influencer_IDs[i];
        transformedposition = influencer_weights[i] * joint_transforms[idx] * bind_matrices[idx] * modelposition;
    }*/


    fs_LightVec = u_Eye - modelposition;//   Compute the direction in which the light source lies

    gl_Position = u_ViewProj * modelposition;// gl_Position is a built-in variable of OpenGL which is used to render the final positions
                                             // of the geometry's vertices
}
