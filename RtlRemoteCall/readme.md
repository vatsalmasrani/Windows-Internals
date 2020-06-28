A very interesting export of ntdll.dll - RtlRemoteCall
it's 100% possible to inject your dll by passing LoadLibrary instead of 
"test" example function ;),however CFG is enforced from Windows 10 builds
by which upon calling RtlRemoteCall would lead to calling LdrControlFlowGuardEnforced
so be careful...

