# libSceJsc

## add Silent stubs

- [JSC::setNeverInline, JSC::setNeverOptimize and JSC::resetSuperSamplerState](../../../core/libs/prx/libSceJsc/Export.cpp) (libSceJsc) - not compared with a console module. Pinned [TestRunnerUtils.cpp](https://github.com/WebKit/WebKit/blob/c55364d53f971f63a709976f168d932d558b8909/Source/JavaScriptCore/runtime/TestRunnerUtils.cpp#L83-L97) returns `jsUndefined()` (encoded `0xa`) for every argument and only flags the function's executable as a JIT tier-up hint; the HLE has no JIT tiers, so the hint is dropped, as NKWebKit's `optimizeNextInvocation` already does. `resetSuperSamplerState` clears the super sampler's private counters, which the HLE never samples, so it is a no-op like NKWebKit's `printSuperSamplerState`. Closes when: compared with a console module.
