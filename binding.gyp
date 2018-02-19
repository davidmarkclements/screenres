{
    "targets": [
        {
            "target_name": "screenres",
            "sources": ["linux.cc", "osx.cc", "win.cc", "screenres.cc"],
            "include_dirs": [ "<!(node -e \"require('nan')\")" ]
        }],
    "conditions": [
      [ "OS=='mac'",
        {
          "xcode_settings": {
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
            'OTHER_CPLUSPLUSFLAGS':[
              "-Wno-c++11-narrowing"
            ]
          },
          "link_settings": {
            "libraries": [
              "-framework",
              "ApplicationServices"
            ]
          }
        }
      ]
    ]
}
