#import <Foundation/Foundation.h>
int main()
{
    @NSAutoreleasePool
        NSLog(@"Hello World!");
    [pool drain];
    return 0;
}
