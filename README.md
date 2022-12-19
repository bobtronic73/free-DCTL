# free-DCTL
a collection of DCTL files, mostly small helpers in DaVinci Resolve

## S-Log Matrix
Applies a color matrix to S-Log footage. The main purpose is to use it on S-Log footage of the Sony PMW-F3 which is lacking a proper color matrix.

Compare the vector scopes of the recorded PMW-F3 S-Log footage (left) and with the applied color matrix (right)
![MatrixTransform](docs/images/matrix_transform.jpg)

Recorded footage. Notice the pale yellows and greens and the magenta/cyan tint.
![StillNoMatrix](docs/images/still_no_matrix.jpg)

Color matrix applied. Notice rich more natural colors.
![StillWithMatrix](docs/images/still_matrix.jpg)
