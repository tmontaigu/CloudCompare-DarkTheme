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

#pragma once

#include "ccStdPluginInterface.h"

class DarkTheme : public QObject, public ccStdPluginInterface {
  Q_OBJECT
  Q_INTERFACES(ccPluginInterface ccStdPluginInterface)

  Q_PLUGIN_METADATA(IID "cccorp.cloudcompare.plugin.DarkTheme" FILE
                        "../info.json")

public:
  explicit DarkTheme(QObject *parent = nullptr);
  ~DarkTheme() override = default;

  void activateQDarkStyle();
  void activateFusionDark();
  void activateDefault();

  QList<QAction *> getActions() override;

private:
  QAction *m_qDarkStyleAction{nullptr};
  QAction *m_fusionDarkAction{nullptr};
  QAction *m_defaultAction{nullptr};
};
