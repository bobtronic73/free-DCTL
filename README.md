# free-DCTL
a collection of DCTL files, mostly small helpers in DaVinci Resolve

## Normalized Color Matrix
Applies a normalized color matrix to video footage. This simplifies the usual 3x3 matrix to six parameters. Tweaking the parameters will retain white balance.

Originally my main purpose was to use it on S-Log footage of the Sony PMW-F3 which is lacking a proper color matrix.
It turned out to be very useful for all kind of footage, not just PMW-F3 footage, as creative color palette tool.
Since the matrix is normalized this makes it much easier than Resolved color mixer for example. Also there is no extra linearization needed for supported spaces.

Compare the vector scopes of the recorded PMW-F3 S-Log footage (left) and with the applied color matrix (right)
![MatrixTransform](docs/images/matrix_transform.jpg)

Recorded footage. Notice the pale yellows and greens and the magenta/cyan tint.
![StillNoMatrix](docs/images/still_no_matrix.jpg)

Color matrix applied. Notice rich more natural colors.
![StillWithMatrix](docs/images/still_matrix.jpg)

### Parameters
* R-G, R-B, G-R, G-B, B-R, B-G - the simplified 2x3 matrix
* Source - the type of source (Linear, S-Log, S-Log3)

### Examples
Matrix to match the Sony PMW-F3 to the Sony F35
* R-G: 0.099
* R-B: 0.075
* G-R: -0.050
* G-B: -0.043
* B-R: 0.020
* B-G: -0.305

## Ramp
A ramp generator. Useful to check out LUT responses and color space transforms etc.
It offer both linear and exposure ramp with either adjustable slope or stops.

### Parameters
* Stops: The linear slope factor or exposure stops when in Exposure mode
* Exposure Ramp: when enabled the ramp is expressed as exposure stops
* Gray: Value of mid gray

## Value
A simple value generator, useful for testing.

### Parameters
* Value: The output value of the generator

## F900 Matrix
Transforms S-Gamut/S-Log1 into F900/S-Log1 color space.