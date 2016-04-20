#include<stdio.h>
#define BUCKET_MAX 10
#define FLOW_MAX 7

int main() {

	int bucket=0, packets, outgoing;

	for (int t = 1; ; t++) {

		printf("\n\nAt Time t=%d sec\n", t);
		printf("\nPackets in Bucket  : %d\n", bucket);
		printf("\nIncomming Packets  : ");
		scanf("%d", &packets);

		if (packets+bucket>BUCKET_MAX) {
			printf("\nPackets discarded  : %d\n", packets+bucket-BUCKET_MAX);
			bucket = BUCKET_MAX;
		}
		else {
			printf("\nNo Packet Discarded\n");
			bucket += packets;
		}

		if (bucket <= FLOW_MAX) {
			outgoing = bucket;
		}
		else {
			outgoing = FLOW_MAX;
			printf("\nLimiting Flow\n");
		}
		printf("\nOutgoing Packets   : %d\n", outgoing);

		bucket -= outgoing;

	}

	return 0;
}



