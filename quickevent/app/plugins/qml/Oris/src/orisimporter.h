#ifndef ORISIMPORTER_H
#define ORISIMPORTER_H

#include <QObject>

#include <functional>

namespace qf { namespace core { namespace network { class NetworkAccessManager; }}}

class OrisImporter : public QObject
{
	Q_OBJECT
public:
	explicit OrisImporter(QObject *parent = 0);

	Q_INVOKABLE void chooseAndImport();
	Q_INVOKABLE void importRegistrations();
private:
	void getJsonToProcess(const QUrl &url, std::function<void (const QJsonDocument &data)> process_call_back);
	qf::core::network::NetworkAccessManager *networkAccessManager();
private:
	qf::core::network::NetworkAccessManager *m_networkAccessManager = nullptr;
};

#endif // ORISIMPORTER_H
