{
    unsigned long warpId = (blockId() * blockDim() + blockThreadId())/32;
    
    ON_BASIC_BLOCK_EXIT:
    {
        if(leastActiveThreadInWarp())
        {
            globalMem[warpId] = globalMem[warpId] + 
                (basicBlockPredicatedInstructionCount() * activeThreadCount());
        }
    
    }
}

