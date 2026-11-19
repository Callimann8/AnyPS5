# libSceNKWebKit

## add Functional

- [WTF::setDataFile(const char*)](../../../core/libs/prx/libSceNKWebKit/src/WtfDataFile.cpp) (libSceNKWebKit) - follows the pinned [DataLog.cpp](https://github.com/neonmodder123/PS5-WebKit-11.x/blob/80f77e94c63ee7202eec3d4b5b1a021dd89011ba/Source/WTF/wtf/DataLog.cpp) PlayStation path (first `%pid` replaced by `getpid`, opened with mode `w`, unbuffered, falling back to borrowed stdout) but is not compared with a console module. Unlike upstream, which builds a new LockedPrintStream over the old one and leaks the replaced stream, the target is swapped under the existing lock and a replaced opened stream is deleted, closing its FILE. Closes when: compared with a console module.

## remove `_ZN3WTF11setDataFileEPKc`
