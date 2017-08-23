{
  "targets":
  [
    {
      "target_name": "cec-client",
      # "type": "executable",
      "sources":
      [
        "src/addon/**/*.cc"
      ],
      "include_dirs":
      [
        "<!@(node -p \"require('node-addon-api').include\")",
        "libcec/include"
      ],
      "dependencies":
      [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],   
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],

      "conditions":
      [
        [
          "OS == 'win'",
          {
            "link_settings":
            {
              "library_dirs":
              [
                "libcec/build/windows/amd64",
                "libcec/build/windows/amd64/lib"
              ],
              "libraries":
              [
                "-lcec",
                "-lp8-platform"
                # "x86/cec.lib",
                # "x86/lib/p8-platform.lib"
              ]
            },
            "copies": [
              {
                "files": ["libcec/build/windows/amd64/cec.dll"],
                "destination": "./"
              }
            ],
            "msbuild_toolset": "v141",
            "msvs_settings":
            {
              "VCCLCompilerTool":
              {
                "ExceptionHandling": 1,
                "RuntimeLibrary": 2 # /MD
              }
            }
          }
        ],
        [
          "OS == 'mac'",
          {
            "xcode_settings":
            {
              "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
              "CLANG_CXX_LIBRARY": "libc++",
              "MACOSX_DEPLOYMENT_TARGET": "10.7"
            }
          }
        ]
      ]
      
    }
  ]
}
