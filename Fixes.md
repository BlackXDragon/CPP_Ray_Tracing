1. *FIXED* - **The rendering processes randomly stops around 3/4 of the way without throwing exceptions when the aspect ratio of the final image is not 1.0 (Return code: -1073740940)**

The error was is lines 25, 27 and 29 of image.cpp. The order of the indices to this->pixels had been reversed.