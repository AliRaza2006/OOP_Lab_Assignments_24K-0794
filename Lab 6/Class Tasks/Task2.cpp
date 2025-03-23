#include <iostream>
#include <string>
using namespace std;

class MediaFile 
{
protected:
    string filePath;
    double size;
public:
    MediaFile(string path, double s) : filePath(path), size(s) {}
    virtual void play() = 0;
    virtual void stop() = 0;
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile 
{
protected:
    string resolution;
public:
    VisualMedia(string path, double s, string res) : MediaFile(path, s), resolution(res) {}
};

class AudioMedia : virtual public MediaFile 
{
protected:
    int sampleRate;
public:
    AudioMedia(string path, double s, int rate) : MediaFile(path, s), sampleRate(rate) {}
};

class VideoFile : public VisualMedia, public AudioMedia 
{
public:
    VideoFile(string path, double s, string res, int rate)
        : MediaFile(path, s), VisualMedia(path, s, res), AudioMedia(path, s, rate) {}

    void play() override 
    {
        cout << "Playing video: " << filePath << " (Size: " << size << " MB, Resolution: " 
             << resolution << ", Sample Rate: " << sampleRate << " Hz)" << endl;
    }

    void stop() override 
    {
        cout << "Stopping video: " << filePath << endl;
    }
};

class ImageFile : public VisualMedia 
{
public:
    ImageFile(string path, double s, string res) : MediaFile(path, s), VisualMedia(path, s, res) {}

    void play() override 
    {
        cout << "Displaying image: " << filePath << " (Resolution: " << resolution << ")" << endl;
    }

    void stop() override 
    {
        cout << "Closing image: " << filePath << endl;
    }
};

class AudioFile : public AudioMedia 
{
public:
    AudioFile(string path, double s, int rate) : MediaFile(path, s), AudioMedia(path, s, rate) {}

    void play() override 
    {
        cout << "Playing audio: " << filePath << " (Sample Rate: " << sampleRate << " Hz)" << endl;
    }

    void stop() override 
    {
        cout << "Stopping audio: " << filePath << endl;
    }
};

int main() 
{
    MediaFile* media[] = {
        new VideoFile("video.mp4", 500, "1920x1080", 44100),
        new ImageFile("image.jpg", 5, "1080x720"),
        new AudioFile("audio.mp3", 10, 44100)
    };

    for (auto& m : media) 
    {
        m->play();
        m->stop();
        delete m;
    }

    return 0;
}