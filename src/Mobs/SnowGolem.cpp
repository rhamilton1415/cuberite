
#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "SnowGolem.h"
#include "../World.h"





cSnowGolem::cSnowGolem(void) :
	super("SnowGolem", mtSnowGolem, "", "", 0.4, 1.8)
{
}





void cSnowGolem::GetDrops(cItems & a_Drops, cEntity * a_Killer)
{
	AddRandomDropItem(a_Drops, 0, 5, E_ITEM_SNOWBALL);
}





void cSnowGolem::Tick(float a_Dt, cChunk & a_Chunk)
{
	super::Tick(a_Dt, a_Chunk);
	if (IsBiomeNoDownfall((EMCSBiome) m_World->GetBiomeAt((int) floor(GetPosX()), (int) floor(GetPosZ())) ))
	{
		TakeDamage(*this);
	}
	else
	{
		if (g_BlockIsSolid[m_World->GetBlock((int) floor(GetPosX()), (int) floor(GetPosY()) - 1, (int) floor(GetPosZ()))])
		{
			m_World->SetBlock((int) floor(GetPosX()), (int) floor(GetPosY()), (int) floor(GetPosZ()), E_BLOCK_SNOW, 0);
		}
	}
}
