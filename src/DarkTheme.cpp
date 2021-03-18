//##########################################################################
//#                                                                        #
//#                CLOUDCOMPARE PLUGIN: DarkThemePlugin                    #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#                             COPYRIGHT: CloudCompare                    #
//#                                                                        #
//##########################################################################

#include <QtGui>

#include "DarkTheme.h"

#include <QApplication>
#include <QtWidgets>

DarkTheme::DarkTheme(QObject *parent)
    : QObject(parent),
      ccStdPluginInterface(":/CC/plugin/DarkThemePlugin/info.json"),
      m_qDarkStyleAction(nullptr) {}

QList<QAction *> DarkTheme::getActions() {
  if (!m_qDarkStyleAction) {
    // Here we use the default plugin name, description, and icon,
    // but each action should have its own.
    m_qDarkStyleAction = new QAction("QDarkStyle", this);
    m_qDarkStyleAction->setToolTip(getDescription());
    m_qDarkStyleAction->setIcon(getIcon());

    // Connect appropriate signal
    connect(m_qDarkStyleAction, &QAction::triggered, this,
            &DarkTheme::activateQDarkStyle);
  }

  if (!m_fusionDarkAction) {
    // Here we use the default plugin name, description, and icon,
    // but each action should have its own.
    m_fusionDarkAction = new QAction("Fusion Dark", this);
    m_fusionDarkAction->setToolTip(getDescription());
    m_fusionDarkAction->setIcon(getIcon());

    // Connect appropriate signal
    connect(m_fusionDarkAction, &QAction::triggered, this,
            &DarkTheme::activateFusionDark);
  }

  if (!m_defaultAction) {
    // Here we use the default plugin name, description, and icon,
    // but each action should have its own.
    m_defaultAction = new QAction("Default Theme", this);
    m_defaultAction->setToolTip(getDescription());
    m_defaultAction->setIcon(getIcon());

    // Connect appropriate signal
    connect(m_defaultAction, &QAction::triggered, this,
            &DarkTheme::activateDefault);
  }

  return {m_qDarkStyleAction, m_fusionDarkAction, m_defaultAction};
}

void DarkTheme::activateQDarkStyle() {
  QFile f(":qdarkstyle/style.qss");

  if (!f.exists()) {
    printf("Unable to set stylesheet, file not found\n");
  } else {
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    static_cast<QApplication *>(QCoreApplication::instance())
        ->setStyleSheet(f.readAll());
  }
}

void DarkTheme::activateFusionDark() {
  static_cast<QApplication *>(QCoreApplication::instance())->setStyleSheet("");
  // set style
  qApp->setStyle(QStyleFactory::create("Fusion"));

  // modify palette to dark
  QPalette darkPalette;
  darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::WindowText, Qt::white);
  darkPalette.setColor(QPalette::Disabled, QPalette::WindowText,
                       QColor(127, 127, 127));
  darkPalette.setColor(QPalette::Base, QColor(42, 42, 42));
  darkPalette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
  darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
  darkPalette.setColor(QPalette::ToolTipText, Qt::white);
  darkPalette.setColor(QPalette::Text, Qt::white);
  darkPalette.setColor(QPalette::Disabled, QPalette::Text,
                       QColor(127, 127, 127));
  darkPalette.setColor(QPalette::Dark, QColor(35, 35, 35));
  darkPalette.setColor(QPalette::Shadow, QColor(20, 20, 20));
  darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
  darkPalette.setColor(QPalette::ButtonText, Qt::white);
  darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText,
                       QColor(127, 127, 127));
  darkPalette.setColor(QPalette::BrightText, Qt::red);
  darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
  darkPalette.setColor(QPalette::Disabled, QPalette::Highlight,
                       QColor(80, 80, 80));
  darkPalette.setColor(QPalette::HighlightedText, Qt::white);
  darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText,
                       QColor(127, 127, 127));

  qApp->setPalette(darkPalette);
}
void DarkTheme::activateDefault() {
  qApp->setPalette(QPalette());
  static_cast<QApplication *>(QCoreApplication::instance())->setStyleSheet("");
}
