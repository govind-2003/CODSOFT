#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void displayImage(const Mat& image, const string& windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, image);
    waitKey(0);
    destroyWindow(windowName);
}

Mat applyGrayscale(const Mat& image) {
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    return gray;
}

Mat applyBlur(const Mat& image, int kernelSize = 5) {
    Mat blurred;
    GaussianBlur(image, blurred, Size(kernelSize, kernelSize), 0);
    return blurred;
}

Mat applySharpen(const Mat& image) {
    Mat sharpened;
    Mat kernel = (Mat_<float>(3,3) << 
                 0, -1,  0, 
                -1,  5, -1, 
                 0, -1,  0);
    filter2D(image, sharpened, image.depth(), kernel);
    return sharpened;
}

Mat adjustBrightnessContrast(const Mat& image, double alpha = 1.0, int beta = 0) {
    Mat adjusted;
    image.convertTo(adjusted, -1, alpha, beta);
    return adjusted;
}

Mat cropImage(const Mat& image, Rect region) {
    return image(region);
}

Mat resizeImage(const Mat& image, Size newSize) {
    Mat resized;
    resize(image, resized, newSize);
    return resized;
}

void saveImage(const Mat& image, const string& filename) {
    imwrite(filename, image);
    cout << "Image saved as " << filename << endl;
}

int main() {
    string imagePath;
    cout << "Enter the path to the image: ";
    cin >> imagePath;

    Mat image = imread(imagePath);
    if (image.empty()) {
        cerr << "Error loading image!" << endl;
        return -1;
    }

    int choice;
    do {
        cout << "\nImage Processing Tool\n";
        cout << "1. Display Image\n";
        cout << "2. Apply Grayscale Filter\n";
        cout << "3. Apply Blur Filter\n";
        cout << "4. Apply Sharpen Filter\n";
        cout << "5. Adjust Brightness/Contrast\n";
        cout << "6. Crop Image\n";
        cout << "7. Resize Image\n";
        cout << "8. Save Image\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                displayImage(image, "Original Image");
                break;
            }
            case 2: {
                Mat gray = applyGrayscale(image);
                displayImage(gray, "Grayscale Image");
                break;
            }
            case 3: {
                Mat blurred = applyBlur(image);
                displayImage(blurred, "Blurred Image");
                break;
            }
            case 4: {
                Mat sharpened = applySharpen(image);
                displayImage(sharpened, "Sharpened Image");
                break;
            }
            case 5: {
                double alpha;
                int beta;
                cout << "Enter alpha (contrast): ";
                cin >> alpha;
                cout << "Enter beta (brightness): ";
                cin >> beta;
                Mat adjusted = adjustBrightnessContrast(image, alpha, beta);
                displayImage(adjusted, "Brightness/Contrast Adjusted Image");
                break;
            }
            case 6: {
                int x, y, width, height;
                cout << "Enter crop region (x y width height): ";
                cin >> x >> y >> width >> height;
                Mat cropped = cropImage(image, Rect(x, y, width, height));
                displayImage(cropped, "Cropped Image");
                break;
            }
            case 7: {
                int newWidth, newHeight;
                cout << "Enter new width and height: ";
                cin >> newWidth >> newHeight;
                Mat resized = resizeImage(image, Size(newWidth, newHeight));
                displayImage(resized, "Resized Image");
                break;
            }
            case 8: {
                string savePath;
                cout << "Enter the save path (with filename and extension): ";
                cin >> savePath;
                saveImage(image, savePath);
                break;
            }
            case 9: {
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    } while (choice != 9);

    return 0;
}
