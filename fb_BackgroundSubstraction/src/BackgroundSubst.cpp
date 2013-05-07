#include "../include/BackgroundSubst.h"

BackgroundSubst::BackgroundSubst()
{
    absoluteSet = true;
    mode = '1';
}

BackgroundSubst::~BackgroundSubst()
{
    //dtor
}

void BackgroundSubst::setAbsolute(bool setting = true){
    absoluteSet = setting;
}
void BackgroundSubst::setAutoresize(bool setting = true){
    autoresizeSet = setting;
}

void BackgroundSubst::setBackground(){
    background = image;
}

void BackgroundSubst::setBackground(ofImage newBackground){
    background = newBackground;
}
void BackgroundSubst::addToBackground(ofImage image){
    ofColor imageColor;
    ofColor backgroundColor;
    ofColor resultColor;

    for(int y = 0; y < image.getHeight(); y++){
		for(int x = 0; x < image.getWidth(); x++){

			imageColor = image.getColor(x, y);
			backgroundColor = background.getColor(x, y);

            resultColor.r = imageColor.r + backgroundColor.r;
            resultColor.g = imageColor.g + backgroundColor.g;
            resultColor.b = imageColor.b + backgroundColor.b;

            background.setColor(x, y, resultColor);
        }
    }

}
void BackgroundSubst::update(){
    image.update();
    background.update();
    result.update();
}
void BackgroundSubst::setMode(int modeSetting){
    mode = modeSetting;
    printf("\n\aMode: %c", mode);
}
ofImage BackgroundSubst::substract(ofImage newImage){

    image = newImage;
    result = image;
    ofColor imageColor;
    ofColor backgroundColor;
    ofColor resultColor;
    unsigned int limit = 100;

//    TODO:
//      Scale Images to same size

    for(int y = 0; y < image.getHeight(); y++){
		for(int x = 0; x < image.getWidth(); x++){

			imageColor = image.getColor(x, y);
			backgroundColor = background.getColor(x, y);

			switch (mode){

                case '1':
                resultColor.r = abs(imageColor.r - backgroundColor.r) > limit ? 255 : 0;
                resultColor.g = abs(imageColor.g - backgroundColor.g) > limit ? 255 : 0;
                resultColor.b = abs(imageColor.b - backgroundColor.b) > limit ? 255 : 0;
                break;

                case '2':
                resultColor.r = (imageColor.r - backgroundColor.r) < 0 ? 0 : (imageColor.r - backgroundColor.r);
                resultColor.g = (imageColor.g - backgroundColor.g) < 0 ? 0 : (imageColor.g - backgroundColor.g);
                resultColor.b = (imageColor.b - backgroundColor.b) < 0 ? 0 : (imageColor.b - backgroundColor.b);
                break;

                case '3':
                resultColor.r = imageColor.r - backgroundColor.r;
                resultColor.g = imageColor.g - backgroundColor.g;
                resultColor.b = imageColor.b - backgroundColor.b;
                break;

                case '4':
                default:
                resultColor.r = abs(imageColor.r - backgroundColor.r);
                resultColor.g = abs(imageColor.g - backgroundColor.g);
                resultColor.b = abs(imageColor.b - backgroundColor.b);
                break;

//                TODO:
//                Black n White case

			};

            result.setColor(x, y, resultColor);
        }
    }

    return result;
}
ofImage BackgroundSubst::getResult(){
    return result;
}
