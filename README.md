![image](https://github.com/JDSherbert/Unreal-Engine-True-First-Person-Template/assets/43964243/6d4c51f2-79da-48ea-a77d-13fc285e8df6)

# Unreal Engine True First Person Template

<!-- Header Start -->
<a href = "https://docs.unrealengine.com/5.3/en-US/"> <img height="40" img width="40" src="https://cdn.simpleicons.org/unrealengine/white"> </a> 
<a href = "https://learn.microsoft.com/en-us/cpp/cpp-language"> <img height="40" img width="40" src="https://cdn.simpleicons.org/c++"> </a>
<img align="right" alt="Stars Badge" src="https://img.shields.io/github/stars/jdsherbert/Unreal-Engine-True-First-Person-Template?label=%E2%AD%90"/>
<img align="right" alt="Forks Badge" src="https://img.shields.io/github/forks/jdsherbert/Unreal-Engine-True-First-Person-Template?label=%F0%9F%8D%B4"/>
<img align="right" alt="Watchers Badge" src="https://img.shields.io/github/watchers/jdsherbert/Unreal-Engine-True-First-Person-Template?label=%F0%9F%91%81%EF%B8%8F"/>
<img align="right" alt="Issues Badge" src="https://img.shields.io/github/issues/jdsherbert/Unreal-Engine-True-First-Person-Template?label=%E2%9A%A0%EF%B8%8F"/>
<img align="right" src="https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2FJDSherbert%2FUnreal-Engine-True-First-Person-Template%2Fhit-counter%2FREADME&count_bg=%2379C83D&title_bg=%23555555&labelColor=0E1128&title=🔍&style=for-the-badge">
<!-- Header End --> 

-----------------------------------------------------------------------

<a href="https://docs.unrealengine.com/5.3/en-US/"> 
  <img align="left" alt="Unreal Engine Template" src="https://img.shields.io/badge/Unreal%20Engine%20Template-black?style=for-the-badge&logo=unrealengine&logoColor=white&color=black&labelColor=black"> </a>

<a href="https://docs.unrealengine.com/5.3/en-US/"> 
  <img align="left" alt="Unreal Engine 5.4" src="https://img.shields.io/badge/Unreal%20Engine%205.4-black?style=for-the-badge&logo=unrealengine&logoColor=white&color=black&labelColor=black"> </a>
  
<a href="https://choosealicense.com/licenses/mit/"> 
  <img align="right" alt="License" src="https://img.shields.io/badge/License%20:%20MIT-black?style=for-the-badge&logo=mit&logoColor=white&color=black&labelColor=black"> </a>
  
<br></br>

-----------------------------------------------------------------------
## Overview
True First Person refers to a perspective in video games where the player's viewpoint is exactly from the character's face, providing an immersive experience as if the player is seeing the game world directly through the character's eyes. This is in contrast to the traditional first-person view, which often only renders the character's hands and weapon, if any, without showing the rest of the body. This perspective is commonly used in AAA first person shooter titles - games such as Far Cry, Call Of Duty, Halo and Mirror's Edge.

This template is a C++ project with Raytracing enabled.
It's built on top of the Third Person Template, with some edits, as if it was a real True First Person implementation from Epic Games.

This code creates the True First Person camera and attaches it to the head bone of the character mesh. 
Note that we need to use a custom `FRotator()` because otherwise the camera will not be aligned correctly.
We also set the location slightly forward on the Y axis so we cannot look down through our own mesh.
```cpp
// SherbertTFPTemplateCharacter.cpp //

// Create a True First Person camera
TrueFirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TrueFirstPersonCamera"));
TrueFirstPersonCamera->SetupAttachment(GetMesh(), "Head");
TrueFirstPersonCamera->SetRelativeLocation(FVector(0.0f, 10.0f, 0.0f));
TrueFirstPersonCamera->SetRelativeRotation(FRotator(0.0f, 90.0f, -90.0f));
TrueFirstPersonCamera->bUsePawnControlRotation = true; // Camera rotates relative to pawn
```

This is also important to disable Controller Rotation because it allows the character to rotate with the camera.
Otherwise, the camera rotates independently of the character which can be disorienting.
```cpp
// SherbertTFPTemplateCharacter.cpp //

// Don't rotate when the controller rotates. Let that just affect the camera.
bUseControllerRotationPitch = false;
bUseControllerRotationYaw = true;
bUseControllerRotationRoll = false;
```

-----------------------------------------------------------------------

