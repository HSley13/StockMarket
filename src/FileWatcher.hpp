#pragma once

#include <QDir>
#include <QDirIterator>
#include <QFileSystemWatcher>
#include <QObject>
#include <QStringList>
#include <QTime>
#include <QTimer>
#include <functional>

class FileWatcher : public QObject {
    Q_OBJECT

  public:
    explicit FileWatcher(std::function<void()> callback);

    void set_directory(const QString &path);

  private:
    void add_paths(const QString &changedPath);
    QStringList find_files(const QString &path);

    QFileSystemWatcher _watcher;
    QTimer _timer;
    QDir _dir;
    std::function<void()> _callback;

  private slots:
    void on_directory_changed(const QString &path);
    void on_file_changed(const QString &path);
};
