#include <iostream>
#include <pcl-1.8/pcl/io/pcd_io.h>
#include <pcl-1.8/pcl/point_cloud.h>
#include <pcl-1.8/pcl/point_types.h>
#include <pcl-1.8/pcl/visualization/pcl_visualizer.h>


using namespace std;

int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    cloud->height = 1;
    cloud->width = 1024;

    cloud->points.resize(cloud->width*cloud->height);

    for(int i=0; i<cloud->width; i++)
    {
        // pcl::PointXYZ p;
        // p.x = rand()%RAND_MAX;
        // p.y = rand()%RAND_MAX;
        // p.z = rand()%RAND_MAX;

        // cloud->points.push_back(p);
        cloud->points[i].x = rand()%RAND_MAX;
        cloud->points[i].y = rand()%RAND_MAX;
        cloud->points[i].z = rand()%RAND_MAX;
    }

    pcl::visualization::PCLVisualizer view("viewr");
    view.addPointCloud(cloud, "cloud");

    view.spin();


    pcl::io::savePCDFileBinary("test.pcd", *cloud);

    return 0;
}

