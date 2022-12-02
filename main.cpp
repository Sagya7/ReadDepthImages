#include <stdio.h>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	std::ifstream fin;
	std::string filename;
	filename = "C:\\Users\\SWalishe\\Desktop\\depth_frame.bin";
	short* frame_buffer_depth = new short[512 * 512];

	FILE *fp;
	fopen_s(&fp, filename.c_str(), "rb");
	int frame = 0;
	while (!feof(fp))
	{
		fread_s(frame_buffer_depth, 512 * 512 * 2, 2, 512 * 512, fp);
		Mat depth_mat = Mat(512, 512, CV_16UC1, frame_buffer_depth);
		if (frame > 30)
		{
			for (int j = 0; j < 512; j++)
			{
				for (int k = 0; k < 512; k++)
				{
					if ((frame_buffer_depth[(k * 512) + j] < 1000) && (frame_buffer_depth[(k * 512) + j] > 0))
					{
						int stop;
						stop = 7;
					}
				}
			}

		}
		frame++;
	}


	return 0;
}