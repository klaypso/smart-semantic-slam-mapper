
# Welcome to the enhanced semantic SLAM mapping project!
=======

#This project blends semantic segmentation with SLAM mapping, contributing to significant advancements in the mapping domain.

Examples
=======
![result1][1]
![result2][6]
![result3][2]
![result4][3]
![result5][4]
![result6][5]

[1]: https://github.com/klaypso/smart-semantic-slam-mapper/blob/master/001.png
[2]: https://github.com/klaypso/smart-semantic-slam-mapper/blob/master/2.png
[3]: https://github.com/klaypso/smart-semantic-slam-mapper/blob/master/3.png
[4]: https://github.com/klaypso/smart-semantic-slam-mapper/blob/master/0002.png
[5]: https://github.com/klaypso/smart-semantic-slam-mapper/blob/master/0002.jpg
[6]: https://github.com/klaypso/smart-semantic-slam-mapper/blob/master/000000.png
Models
====

>- Model files are absent here; consider modifying this file: segnet.cpp

>- [ ] The semantic segmentation method is influenced by Alex Kendall's exemplary research

>- [ ] Caffe Segnet is a modified version of **Caffe** supporting the **SegNet** architecture

>- [ ] The mapping architecture takes inspiration from GaoXiang's work and leans on **ORB-SLAM**.

----
Getting Started
=======

This guidance helps you to explore the code and its requirements.

#OpenCV

OpenCV is used in this project for image and feature manipulations. Instructions to download and install can be found at: http://opencv.org. OpenCV 2.4.x is essential.

Note: The code is incompatible with OpenCV3.0

Eigen 3.0+
======

PCL 1.7
======

DBoW2(for loop closure) and g2o(for solving pnp)
======