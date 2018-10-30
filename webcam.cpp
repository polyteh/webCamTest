#include <opencv2/opencv.hpp>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
        VideoCapture cap(0); //открыть камеру по-умолчанию

        if (cap.isOpened() == false) 
		{
                cout << "Cannot open the video camera" << endl;
                cin.get();
                return -1;
        }

        double w = cap.get(CV_CAP_PROP_FRAME_WIDTH); //получить ширину кадра
        double h = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //получить высоту кадра

        cout << "Resolution of the video : " << w << " x " << h << endl;

        string windowCamName = "My Camera Feed";
        namedWindow(windowCamName);
		moveWindow(windowCamName,50,50);//начальная позиция окна

        while (true) 
		{
                Mat frame;

                if (!cap.read(frame)) // читаем кадр
				{
                        cout << "Video camera is disconnected" << endl;
                        cin.get();
                        break;
                }

		for(int y=static_cast<int>(frame.rows/3);y<static_cast<int>((2*frame.rows)/3);y++)//инвертируем центральную часть картинки при делении 3*3
				{
        for(int x=static_cast<int>(frame.cols/3);x<static_cast<int>((2*frame.cols)/3);x++)
         {
			Vec3b color = frame.at<Vec3b>(Point(x,y));
            color[0] = 255-color[0];
            color[1] = 255-color[1];
            color[2] = 255-color[2];
			frame.at<Vec3b>(Point(x,y)) = color;

         }
				}
				resize(frame,frame,Size(2*w,2*h),0,0,INTER_LINEAR_EXACT); //увеличиваем в два раза
                imshow(windowCamName, frame); // показать кадр
				
                if (waitKey(10) == 27) //выход по Esc
				{
                        cout << "Esc key is pressed by user. Stoppig the video" << endl;
                        break;
                }
        }
		
		cvDestroyAllWindows();
		waitKey(100);
				
        return 0;
}