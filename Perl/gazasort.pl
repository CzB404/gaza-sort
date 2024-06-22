use strict;
use warnings;
use List::Util qw(any);

sub gaza_sort {
    my @arr = @_;
    while (!is_sorted(@arr)) {
        splice @arr, int(rand(@arr)), 1;
    }
    return @arr;
}

sub is_sorted {
    my @arr = @_;
    for my $i (1 .. $#arr) {
        return 0 if $arr[$i - 1] > $arr[$i];
    }
    return 1;
}
