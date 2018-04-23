# Reflections

## 1. Describe the effect each of the P, I, D components had in your implementation.

PID controller stands for proportional Integral Derivative controller. As the name suggests, these types of controllers have a proportional, derivative and an integral element. Each of this brings in a different characteristic to the controller.
I experimented with each of these components separately and also in combination to find their effect.

**Proportional controller**
This component changes steer angle proportional to the Cross Track Error (CTE). That means if the CTE is large the controller will generate a high value of steering angle. A proportionality constant is used represented as 'Kp' in the code. Using the proportionality part alone in the PID controller works fine initially when the car is moving through a straight track. Once curvy tracks are encountered the car seems to take the first turns properly but is unable to recover at the proper location, instead it overshoots. In no time this oscillations increase and the car goes out of the track. As discussed in the lectures, this type of controllers over and under shoot above and below the required values.

**Integral Controller**
This component adds up all the errors and provides a value proportional to this sum(Integral). This typically has a smoothing effect on the oscillations helping in damping the oscillations. Adding a value for 'Ki' stablised the car.

**Differential Controller**
This part adds a value proportional to the derivative of the CTE, ie difference between previous and current CTE. The issue i found with P and I alone is that the car is less responsive to the changes in CTE. The effect is quite delayed. Adding a small value for the differential constant fixed this issue. Increasing this above a purticular value caused the opposite effect making the car over responsive.

## 2. Describe how the final hyperparameters were chosen.

I used **manual tuning** to find appropriate values for the constants. Initially i started with P part alone and found that the car quickly started oscillating after finding the curves on the road and in no time went out of track. I then introduced I part by putting a small value for 'Ki' this pretty much did the work. The car became stable. The only problem which remained was that the car was not much responsive this was evident when the car was taking the two huge turns on the given road. Finally introduction of the D part fixed this for me.




