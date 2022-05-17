#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

int
main()
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
	
	// Fill in the cloud data
	pcl::PCDReader reader;
	// Replace the path below with the path where you saved your file
	reader.read<pcl::PointXYZ>("table_scene_lms400.pcd", *cloud);	//从磁盘中读点云文件
	
	std::cerr << "Cloud before filtering: " << std::endl;
	std::cerr << *cloud << std::endl;
	
	// Create the filtering object 创建统计滤波器对象,所有与查询点的平均距离大于 1 个标准差的点都将被标记为异常值并被删除。
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;	
	sor.setInputCloud(cloud);
	sor.setMeanK(50);
	sor.setStddevMulThresh(1.0);
	sor.filter(*cloud_filtered);
	
	std::cerr << "Cloud after filtering: " << std::endl;
	std::cerr << *cloud_filtered << std::endl;
	
	pcl::PCDWriter writer;
	writer.write<pcl::PointXYZ>("table_scene_lms400_inliers.pcd", *cloud_filtered, false);
	
	sor.setNegative(true);
	sor.filter(*cloud_filtered);
	writer.write<pcl::PointXYZ>("table_scene_lms400_outliers.pcd", *cloud_filtered, false);
	
	return (0);
}