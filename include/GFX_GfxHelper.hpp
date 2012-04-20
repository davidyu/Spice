#ifndef GFXHELPER_H
#define GFXHELPER_H

namespace GFX
{
    inline unsigned int GetColourInHex(unsigned int col)
    { return (col & 0xffffff00) >> 8); }
} // End namespace GFX

#endif // GFXHELPER_H
