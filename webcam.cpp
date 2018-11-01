#include <opencv2/opencv.hpp>
//#include<iostream>
//#include <cstdio>

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

        double w = cap.get(CAP_PROP_FRAME_WIDTH); //получить ширину кадра
        double h = cap.get(CAP_PROP_FRAME_HEIGHT); //получить высоту кадра

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
				
				//инвертируем центральную часть картинки при делении 3*3
				int xDivCount=3;
				int yDivCount=3; //ввел эти переменные для того, чтобы быстро удобно было изменять количество частей, на которые делится исходная картинка
				

				//для следующей строки для конструктора класса Rect дважды вычисляется одно и то же выражение. Оно довольно простое, поэтому вводить доп. переменные для уменьшения врем-ени вычисления в данном случае, наверное, нецелесообразно
				Mat negativeFrame (frame, Rect(static_cast<int>(frame.cols/xDivCount),static_cast<int>(frame.rows/yDivCount),static_cast<int>(frame.cols/xDivCount),static_cast<int>(frame.rows/yDivCount)));
				bitwise_not(negativeFrame,negativeFrame);
				
				resize(frame,frame,Size(2*w,2*h),0,0,INTER_CUBIC);//увеличиваем в два раза. В мануале рекомендуют INTER_CUBIC (более медленно) или INTER_LINEAR. Существенной разницы не заметил.
				//resize(frame,frame,Size(2*w,2*h),0,0,INTER_LINEAR);
                imshow(windowCamName, frame); // показать кадр
				
                if (waitKey(10) == 27) //выход по Esc
				{
                        cout << "Esc key is pressed by user. Stoppig the video" << endl;
                        break;
                }
        }
		
		waitKey(100);
				
        return 0;
}