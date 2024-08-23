# Xbox Application : Example Project Overview

This file contains a summary of what you will find in each of the files that
make up your Xbox application.

### Example_Project.vcproj
    This is the visual studio project file. 
    It contains information about the version of Visual C++ we use, build information, platform configurations and project features.

# C++ Files

### Example_Project.cpp
    This is the main application source file.
    Manages scenes and holds the main game loop.

### Time.cpp, Time.h
    Holds information about time, such as the total game time, and the time since last frame (deltaTime).
    
### Rendering.cpp, Rendering.h
    Handles various rendering tasks, such as setting up matrices, rendering text and initialising DirectX.

### Mesh.cpp, Mesh.h
    Holds Data for meshes and has the render code.

### SystemIO.cpp, SystemIO.h
    Handles File loading.

### Sound.cpp, Sound.h
    handles loading and playing audio files.

### Input.cpp, Input.h
    Handles Gamepad Input.

### Scene.cpp, Scene.h
    Base class for scenes.

### Debug.cpp, Debug.h
    ! Not Implemented! 
    will contain script for displaying debug text on screen.
 
## Scenes

### StartMenuScene.cpp, StartMenuScene.h
    Renders an image and checks for controller input to switch to next scene.

### GameScene.cpp, GameScene.h
    Renders Models and has Controller input for moving the camera around.


## Other Files

### Media Folder
    Holds all our textures, models and audio files.

## Other notes:




