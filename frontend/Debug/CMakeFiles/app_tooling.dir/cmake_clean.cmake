file(REMOVE_RECURSE
  "stockMarket/customedModules/BackGround.qml"
  "stockMarket/customedModules/ButtonImage.qml"
  "stockMarket/customedModules/HomeWindow.qml"
  "stockMarket/customedModules/InputField.qml"
  "stockMarket/customedModules/Main.qml"
  "stockMarket/customedModules/MenuPanel.qml"
  "stockMarket/customedModules/RoundedButton.qml"
  "stockMarket/icons/filter_icon.png"
  "stockMarket/icons/home_icon.png"
  "stockMarket/icons/profile_icon.png"
  "stockMarket/icons/search_icon.png"
  "stockMarket/icons/stats_icon.png"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/app_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
