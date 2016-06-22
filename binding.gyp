{
    "targets": [
        {
            "target_name": "screenres",
            "include_dirs": [ "<!(node -e \"require('nan')\")" ],
    'cflags': [
      '-Wall',
      '-Wparentheses',
      '-Winline',
      '-Wbad-function-cast',
      '-Wdisabled-optimization'
],
    "conditions": [
      [ "OS=='mac'",
        {
             'include_dirs': [
          'System/Library/Frameworks/CoreFoundation.Framework/Headers',
          'System/Library/Frameworks/Carbon.Framework/Headers',
          'System/Library/Frameworks/ApplicationServices.framework/Headers',
          'System/Library/Frameworks/CoreGraphics.framework/Headers',

],
          'link_settings': {
              "libraries":[
                '-framework Carbon',
                '-framework CoreFoundation',
                "-framework CoreGraphics",
                "-framework ApplicationServices",
                '-framework OpenGL'
              ]
            }
        }
      ]
    ],
    "sources": ["linux.cc", "osx.cc", "screenres.cc"],
    }]
}
