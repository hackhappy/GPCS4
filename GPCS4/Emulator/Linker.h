#pragma once

#include "GPCS4Common.h"
#include "SceModuleSystem.h"
#include "Module.h"
#include <string>

class CLinker
{
public:
	CLinker();
	CLinker(CSceModuleSystem &modSystem) : m_modSystem{modSystem} {};

	bool ResolveSymbol(const std::string &strModName,
					   const std::string &strLibName,
					   uint64 nNid,
					   void **ppAddress) const;

	bool resolveSymbol(MemoryMappedModule const &mod,
					   std::string const &name,
					   uint64_t *addr) const;

	bool relocateModules();

private:
	bool relocateModule(MemoryMappedModule &mod);
	bool relocateRela(MemoryMappedModule &mod);
	bool relocatePltRela(MemoryMappedModule &mod);
	CSceModuleSystem &m_modSystem;
};
