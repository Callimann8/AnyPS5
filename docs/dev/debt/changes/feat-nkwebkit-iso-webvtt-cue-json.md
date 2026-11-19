# libSceNKWebKit

## add Functional

- [ISOWebVTTCue::toJSONString](../../../core/libs/prx/libSceNKWebKit/src/WebCoreIsoVttCue.cpp) (libSceNKWebKit) - not compared with a console module. Follows the pinned [ISOVTTCue.cpp](https://github.com/WebKit/WebKit/blob/e12a212a531aeddc11259e8515671cf5188e038d/Source/WebCore/platform/graphics/iso/ISOVTTCue.cpp#L118-L135) release build (`LOG_DISABLED`, so no `text` key): `sourceId`, `id`, `originalStartTime` and `settings` are URL-escaped and quoted, then `presentationTime` and `duration` are written as shortest doubles, with `null` for a non-finite time, in insertion order, without going through a `JSON::Object`. A null cue throws. Closes when: compared with a console module.
