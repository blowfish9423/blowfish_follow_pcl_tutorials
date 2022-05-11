# blowfish_follow_pcl_tutorials
  学习PCL tutorials的例子
  滤波学习
    filter 
      voxel_grid 主要用于下采样 https://pcl.readthedocs.io/projects/tutorials/en/master/voxel_grid.html#voxelgrid
        点云往往较为密集。过多的点云数据对后续的分割工作带来困难。体素法滤波可以达到下采样的同时不破坏点云本身几何结构的功能。
        体素滤波，大幅减少点云数目，减少点云数据，并同时保持点云的形状特征，在提高配准、曲面重建、形状识别等算法速度中非常实用。

        它的原理是根据输入的点云，首先计算一个能够刚好包裹住该点云的立方体，然后根据设定的分辨率，将该大立方体分割成不同的小立方体。对于每一个小立方体内的点，计算他们的质心，并用该质心的坐标来近似该立方体内的若干点

    passthrough https://pcl.readthedocs.io/projects/tutorials/en/master/passthrough.html#passthrough
      直通滤波的作用是过滤掉在指定维度方向上取值不在给定值域内的点。
      首先，指定一个维度以及该维度下的值域，其次，遍历点云中的每个点，判断该点在指定维度上的取值是否在值域内，删除取值不在值域内的点，最后，遍历结束，留下的点即构成滤波后的点云。直通滤波器简单高效，适用于消除背景等操作。
          
