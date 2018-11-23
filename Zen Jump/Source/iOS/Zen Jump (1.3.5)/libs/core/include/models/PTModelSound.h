#ifndef PTMODELSOUND_H
#define PTMODELSOUND_H

#ifdef __QT__
#include <QtMultimedia/QMediaPlayer>
#include <QFileInfo>
#endif

#include "PTModel.h"

USING_NS_CC;

class PTModelSound : public PTModel {
public:
    PTModelSound(const CCString &name = CCString());
    ~PTModelSound();
    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    CCString fileName() const;
    CCString filePath() const;

    static PTModel *   create() {
        return new PTModelSound();
    }

    void preload();
    void play( bool looped = false);
    void playAsBackground( bool looped = false);
    void pause();
    void stop();

    bool isPlaying() const;

#ifdef __QT__
    static PTModelSound *create(const QUrl &url);

    void setSoundFile(const CCString &filePath);
    void deleteSoundFile();
    bool isEmpty() ;
#endif


private:    
    unsigned int _soundId;
    bool _isBackground;
    friend class PTModelController;
};

#endif // PTMODELSOUND_H
