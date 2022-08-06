#include <iostream>
#include <sstream>
#include <ctime>

#include "opencv2/opencv.hpp"
#include "cppflow/ops.h"
#include "cppflow/model.h"
#include "cppflow/tensor.h"

using namespace std;

int main() {
    //Load model
    cppflow::model model("../model");
    clock_t start = clock();
    int j = 0;
    string img_path = "./cache.jpg";
    cv::VideoCapture capture(0);
    cv::Mat img_read;
    cv::Mat norm_image;
    while (j <= 500){
        //Image preprocess
        capture.read(img_read);
        cv::imshow("Image", img_read);
        cv::imwrite(img_path, img_read);
        cppflow::tensor image = cppflow::decode_image(cppflow::read_file(img_path));
        //cout<<image.shape()<<endl;
        image = cppflow::expand_dims(image,0);
        image = cppflow::cast(image, TF_INT8, TF_FLOAT);
        cppflow::tensor box = {0.5f,1.0f,0.25f,0.75f};
        box = cppflow::expand_dims(box,0);
        cppflow::tensor endimg = cppflow::crop_and_resize(image,box,{0},{128,128});
        //Run
        auto output = model(endimg);
        //Show the result
        cv::waitKey(1);
        cout << output << endl;
        ++j;
    }

    clock_t end = clock();
    double endtime=(end-start)/CLOCKS_PER_SEC;
    double ave_time = endtime/j;
    int fps = 1/ave_time;
    cout << "average processing time: " << ave_time << endl;
    cout << "average fps: " << fps <<endl;
    int m = 0;
    cin >> m;
	return 0;
}
