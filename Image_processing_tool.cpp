#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat image, editedImage;

// Display Menu
void showMenu() {
    cout << "\n--- IMAGE PROCESSING TOOL ---\n";
    cout << "1. Load Image\n";
    cout << "2. Display Image\n";
    cout << "3. Convert to Grayscale\n";
    cout << "4. Apply Blur\n";
    cout << "5. Sharpen Image\n";
    cout << "6. Adjust Brightness/Contrast\n";
    cout << "7. Resize Image\n";
    cout << "8. Crop Image\n";
    cout << "9. Save Image\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

// Load Image
void loadImage() {
    string path;
    cout << "Enter image path: ";
    cin >> path;
    image = imread(path);
    if (image.empty()) {
        cout << "Failed to load image!" << endl;
    } else {
        cout << "Image loaded successfully.\n";
        editedImage = image.clone();
    }
}

// Display Image
void displayImage() {
    if (editedImage.empty()) {
        cout << "No image to display!" << endl;
        return;
    }
    imshow("Image", editedImage);
    waitKey(0);
    destroyAllWindows();
}

// Grayscale Filter
void convertToGrayscale() {
    if (!editedImage.empty())
        cvtColor(editedImage, editedImage, COLOR_BGR2GRAY);
    cout << "Converted to Grayscale.\n";
}

// Blur Filter
void applyBlur() {
    if (!editedImage.empty()) {
        int k;
        cout << "Enter kernel size (odd number): ";
        cin >> k;
        GaussianBlur(editedImage, editedImage, Size(k, k), 0);
        cout << "Blur applied.\n";
    }
}

// Sharpen Image
void sharpenImage() {
    if (!editedImage.empty()) {
        Mat kernel = (Mat_<float>(3, 3) <<
            0, -1, 0,
            -1, 5, -1,
            0, -1, 0);
        filter2D(editedImage, editedImage, editedImage.depth(), kernel);
        cout << "Sharpen applied.\n";
    }
}

// Brightness & Contrast
void adjustBrightnessContrast() {
    double alpha;
    int beta;
    cout << "Enter contrast (alpha > 1.0 = higher): ";
    cin >> alpha;
    cout << "Enter brightness (beta): ";
    cin >> beta;
    editedImage.convertTo(editedImage, -1, alpha, beta);
    cout << "Brightness/Contrast adjusted.\n";
}

// Resize Image
void resizeImage() {
    int width, height;
    cout << "Enter new width: ";
    cin >> width;
    cout << "Enter new height: ";
    cin >> height;
    resize(editedImage, editedImage, Size(width, height));
    cout << "Image resized.\n";
}

// Crop Image
void cropImage() {
    int x, y, w, h;
    cout << "Enter x, y, width, height to crop: ";
    cin >> x >> y >> w >> h;
    Rect roi(x, y, w, h);
    editedImage = editedImage(roi);
    cout << "Image cropped.\n";
}

// Save Image
void saveImage() {
    string savePath;
    cout << "Enter filename to save (e.g., output.jpg): ";
    cin >> savePath;
    imwrite(savePath, editedImage);
    cout << "Image saved as " << savePath << endl;
}

// Main Function
int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: loadImage(); break;
            case 2: displayImage(); break;
            case 3: convertToGrayscale(); break;
            case 4: applyBlur(); break;
            case 5: sharpenImage(); break;
            case 6: adjustBrightnessContrast(); break;
            case 7: resizeImage(); break;
            case 8: cropImage(); break;
            case 9: saveImage(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
