#ifndef PTMODELCONTROLLER_H
#define PTMODELCONTROLLER_H

#include "cocos2d.h"
#include <map>

using namespace cocos2d;

class PTModel;
class PTModelSprite;
class PTModelSound;

typedef PTModel *(*CreatePTModelFn)(void);

typedef enum{
    PTModelControllerDataTypeAttributes = 0,
    PTModelControllerDataTypeConnections = 1,

} PTModelControllerDataType;

class PTModelController {
public:    
    static PTModelController *shared();
    static void resetShared();

    PTModelController &operator=(const PTModelController &) { return *this; }

    static unsigned int nextId();

    void addModel( PTModel *model );
    void insertModel( unsigned int index, PTModel *model );
    unsigned int indexOfModel( PTModel *model ) const;
    void removeModel( PTModel *model );

    CCArray *getModelArray( const std::string &className );
    void setModelArray( const std::string &className, CCArray *array );

    PTModel *getModel( const std::string &className );
    PTModel *getModel( unsigned int id );

    void saveSpriteToFile( PTModelSprite *model );
    void loadSpriteFromFile( PTModelSprite *model );
    void copySpriteFile(PTModelSprite *original, PTModelSprite *copy);
    bool deleteSpriteFile( PTModelSprite *model );

    PTModel *createModel( const std::string &className );

    PTModelSprite *getSpriteById( int id );

    bool updateLoadingQueue( const char* resourceFolder );
    void loadFromFile( CCString fileName );

    bool isChanged() const;

    // returns true no previous sessions were found
    bool isEmpty() const;

    bool loadDataForClass( CCString *fileName, PTModelControllerDataType dataType );

    int fileLoadingProgress();

    void clean();

    //QT specific part
#ifdef __QT__
    static QString rootTempDirPath();

    void initDefaultModelSet();
    void initWorkingFolder();

    QString saveSoundFile( PTModelSound *model, const QString &sourceFilePath );
    QString getSoundFileName( PTModelSound *model );
    bool deleteSoundFile( PTModelSound *model );
    bool isEmptySoundFile( PTModelSound *model );

    bool isWorkDirEmpty();
    QStringList getSessionsList();

    void copyPath(QString src, QString dst);
    QString getWorkingPath( ) { return _workingPath; }
    QString savedFilePath;
    bool loadFromFile( QString fileName );
    bool saveToFile( QString fileName );
    bool saveSession();

    bool isLoading();
    void setIsLoading(bool);

    bool writeDataForClass( CCString *className, PTModelControllerDataType dataType );


    QString errorString() const;
    void clearErrorString();

    bool loadExistingSession();
    bool loadExistingSession( const QString & );

    bool compressFilesToArhive(QString basePath, QStringList filesList, QString archiveName );

    void checkSpriteFiles();

    void onModelChange(QString className);
#endif

private:
    // Model Controller is singleton object so there is no ability to create this object explicitly.
    // Use PTModelController::shared() method to get access to singleton instance instead.
    explicit PTModelController( );
    virtual ~PTModelController( );

    void init();

    void addClass(const std::string &className, CreatePTModelFn pfnCreate);

#ifdef __QT__
    bool compressWorkingFiles( QString fileName );
    void workingFiles( QString path, QStringList &list );

    // remove folder of current session
    void removeWorkingFolder();

    void checkAtlasFiles();
    void checkFontFiles();
#endif

    cocos2d::CCDictionary *_data;
    typedef std::map<std::string, CreatePTModelFn> PTModelFactoryMap;
    PTModelFactoryMap _factoryMap;
    bool _isEmpty;

    typedef std::map<unsigned int, PTModel*> PTModelIdMap;
    PTModelIdMap _modelIdMap;

    int _fileLoadCounter;
    int _fileSectionLoadCounter;
    int _fileLoadingMode; // 0 - loading data, 1 - loading connections, 2 - loading complete
    int _fileLoadingProgress;

#ifdef __QT__
    QString _workingPath;
    QStringList _ignoreList;
    QString _errorString;

    QMap<QString, bool> _changeModelMap;
    bool _isLoading;

    void splitVersionNumbers(char* veriosnString, int *v1, int *v2, int *v3);

    //PATCH SECTION
    void pathForObjectSorting();  // since BBox 1.0.9
    void patchForFileLoading( QFileInfo inputFileInfo ); // since BBox 1.0.14
    void patchForJoystick(); // since BBox 1.1
    void patchForCharacterBulletsCollisionType(); // since BBox 1.1
    void patchForDestroyType(); //since BBox 1.1

#endif




};



#endif // PTMODELCONTROLLER_H
