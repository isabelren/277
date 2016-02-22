HW2
3.3 Documentation

Upon starting, the screen will be dark because the body (a red cylinder) is at (0,0,0). To move the camera out, press the minus (-) sign. To zoom in, press (+), with the shift button. Use the arrow keys to adjust phi and theta. You can also click and drag to modify the Theta and Phi angles (Extra Credit).

To change transformations, click on a node and choose a transformation from the combo box. When a node is highlighted in QTreeWidget, the node and all of its children will turn green. To make a new node, click on the middle tab and then select geometry, a color, and click on Add Node. You can also rename the node underneath 'Add Node'.

To delete a node, you can choose to either delete the node and all of its children or reparent the node's children to its parent. (Extra Credit 5 pts) This reparenting is reflected in the QTreeWidget

3.4 Conceptual Questions

The problem with polar coordinates is that if you rotate one angle 90 degrees, they rotate around the same angle and you lose a degree of freedom. When the camera is aligned with the pole, you can only rotate the camera along one axis.
With Euler Angles, we encounter gimbal lock. When two of the three angles line up, you still lose a degree of freedom

In GLSL, a uniform variable is a static variable- everyone in the frame shares the same value. On the other hand, an "in" variable is an input variable, or a constructor variable. It is read only. 

GPUs have more processor cores than CPUs do, which allows it to do a lot of the computing needed in graphics simulations. The GPU cores are weaker, and CPU has one powerful processor core. GPU is good at doing simple manipulations to a large set of data.

A view matrix is applied before a projection matrix because a camera needs to be set up before the scene is projected from 3D space into 2D space. If we do not have a camera to view the scene from, we have no way of knowing what angle to view the scene from to project it into 2D coordinates. If the view matrix is applied after the projection matrix, the forms will be distorted since we've already projected the 3D coordinates into 2D space.
We can figure out whether or not a point will appear on our screen by looking at the coordinates- if any of the values are out of the range of the box made by the coordinates [-1,-1] and [1,1], we will not see them on the screen. In other words, if any of the coordinates are less than -1 or greater than 1, we will not see the point on the screen since it is outside of the frustrum.

We can apply the inverse matrices of the projection and view matrices to compute the point in 3D space a fragment covers. By applying the inverse projection matrix, we will get the camera coordinates. Then, by applying the inverse view matrix, we will get the 3D world coordinates.

