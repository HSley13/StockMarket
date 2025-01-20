file(REMOVE_RECURSE
  "StockMarket/customedModules/BackGround.qml"
  "StockMarket/customedModules/ButtonImage.qml"
  "StockMarket/customedModules/CandleStick.qml"
  "StockMarket/customedModules/HomeWindow.qml"
  "StockMarket/customedModules/InputField.qml"
  "StockMarket/customedModules/Main.qml"
  "StockMarket/customedModules/MenuPanel.qml"
  "StockMarket/customedModules/Metrics.qml"
  "StockMarket/customedModules/PolarGraph.qml"
  "StockMarket/customedModules/Profile.qml"
  "StockMarket/customedModules/RoundedButton.qml"
  "StockMarket/icons/filter_icon.png"
  "StockMarket/icons/home_icon.png"
  "StockMarket/icons/profile_icon.png"
  "StockMarket/icons/search_icon.png"
  "StockMarket/icons/stats_icon.png"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/app_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
