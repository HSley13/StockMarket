#include "FileWatcher.hpp"

FileWatcher::FileWatcher(std::function<void()> callback)
    : _callback(callback) {
    QObject::connect(&_watcher, &QFileSystemWatcher::directoryChanged, this, &FileWatcher::on_directory_changed);
    QObject::connect(&_watcher, &QFileSystemWatcher::fileChanged, this, &FileWatcher::on_file_changed);

    _timer.setInterval(100);
    _timer.setSingleShot(true);

    QObject::connect(&_timer, &QTimer::timeout, _callback);
}

void FileWatcher::set_directory(const QString &path) {
    if (!_watcher.files().isEmpty())
        _watcher.removePaths(_watcher.files());

    if (!_watcher.directories().isEmpty())
        _watcher.removePaths(_watcher.directories());

    if (!_watcher.addPath(path)) {
        qWarning() << "Could not add path:" << path << QTime::currentTime().toString() << "\n";
    } else {
        _dir.setPath(path);
        add_paths(path);
    }
}

void FileWatcher::add_paths(const QString &changedPath) {
    QStringList files{find_files(changedPath)};

    QStringList existingPaths{_watcher.files()};
    for (const QString &file : existingPaths) {
        if (!files.contains(file)) {
            _watcher.removePath(file);
        }
    }

    for (const QString &file : files) {
        if (!_watcher.files().contains(file)) {
            _watcher.addPath(file);
        }
    }

    _timer.start();
}

QStringList FileWatcher::find_files(const QString &path) {
    QStringList files;

    QDirIterator it(path, QStringList() << "*.qml", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        files.append(it.next());

    return files;
}

void FileWatcher::on_directory_changed(const QString &path) {
    add_paths(path);
    qDebug() << "Directory changed:" << path << QTime::currentTime().toString() << "\n";
}

void FileWatcher::on_file_changed(const QString &path) {
    _timer.start();
    qDebug() << "File changed:" << path << QTime::currentTime().toString() << "\n";
}
