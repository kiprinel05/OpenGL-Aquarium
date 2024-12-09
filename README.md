# Virtual Aquarium Simulation

### Team Members:
- **Dumitrașc Ciprian**
- **Ilie Paul**
- **Bangala Costin**

---

## Project Overview
This project simulates a virtual 3D aquarium using **C++** and **OpenGL**. It creates an interactive and immersive experience with animated fish, aquatic plants, decorative stones, and rising air bubbles. The goal is to build a realistic and visually appealing underwater environment that allows user interaction.

---

## Features

### Functional Requirements
1. **Animated Fish**:
   - Smooth and natural movement (using sinusoidal paths or Bézier curves).
   - Fish of varying sizes and colors.
   - Basic AI to avoid collisions with other fish and obstacles.

2. **Decorative Plants and Stones**:
   - Flexible plants that sway gently (simulating water currents).
   - Realistic textures for stones and sand.

3. **Air Bubbles**:
   - Random generation of bubbles from the aquarium's bottom.
   - Vertical movement with size and speed variations.
   - Burst animation upon reaching the surface.

4. **User Interaction**:
   - Change the camera's point of view (rotate/zoom).
   - Add or remove fish and other elements dynamically using the keyboard or mouse.

---

### Technologies Used
- **Programming Language**: C++
- **Graphics Libraries**: OpenGL
- **Additional Libraries**:
  - **GLFW/GLUT**: For window management and user input handling.
  - **GLM**: For mathematical operations (transformations, matrices).
  - **SOIL**: For texture loading.

---

## Technical Implementation

1. **Scene Structure**:
   - Static Objects: Plants and stones.
   - Dynamic Objects: Fish and air bubbles.
   - Lighting system for enhanced realism.

2. **Animations**:
   - Transformation techniques (translate, rotate, scale) for dynamic objects.
   - Fish movement algorithms (random and path-based).

3. **Water Simulation**:
   - Subtle reflections and refractions to mimic water effects.
   - Semi-transparent texture for the water surface.

4. **Output**:
   - The aquarium is displayed in an interactive 3D window.
   - Smooth animations for a realistic and synchronized experience.
   - Additional visual effects such as underwater lighting and optical distortions.

---

## Optional Extensions
- Interactive menu for additional controls and features.
- Audio effects such as bubbling sounds and ambient underwater noises.

---
