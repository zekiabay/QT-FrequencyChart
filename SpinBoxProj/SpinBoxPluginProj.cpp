#include "SpinBox.h"
#include "SpinBoxPluginProj.h"

#include <QtPlugin>

SpinBoxPluginProj::SpinBoxPluginProj(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void SpinBoxPluginProj::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool SpinBoxPluginProj::isInitialized() const
{
    return m_initialized;
}

QWidget *SpinBoxPluginProj::createWidget(QWidget *parent)
{
    return new SpinBox(parent);
}

QString SpinBoxPluginProj::name() const
{
    return QLatin1String("SpinBox");
}

QString SpinBoxPluginProj::group() const
{
    return QLatin1String("");
}

QIcon SpinBoxPluginProj::icon() const
{
    return QIcon();
}

QString SpinBoxPluginProj::toolTip() const
{
    return QLatin1String("");
}

QString SpinBoxPluginProj::whatsThis() const
{
    return QLatin1String("");
}

bool SpinBoxPluginProj::isContainer() const
{
    return false;
}

QString SpinBoxPluginProj::domXml() const
{
    return QLatin1String("<widget class=\"SpinBox\" name=\"spinBox\">\n</widget>\n");
}

QString SpinBoxPluginProj::includeFile() const
{
    return QLatin1String("SpinBox.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(SpinBoxPluginProj, SpinBoxPluginProj)
#endif // QT_VERSION < 0x050000
