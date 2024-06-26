
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static int findConnectedComponents(long[] nums) {
        Result result = new Result();
        int n = nums.length;
        UF[] mem = new UF[0x000F_FFFF + 1];
        mem[0] = new UF(64);
        generateAndAdd(0, n, nums, 0, mem, result);
        return result.sum;
    }
    
    private static void generateAndAdd(int i, int n, long[] nums,
                                       int indices, UF[] mem, Result result) {
        if (i == n) {
            if (indices == 0) {
                result.sum += mem[0].components;
                return;
            }
            int index = 19;
            while (index >= 0 && ((1 << index) & indices) == 0) {
                index--;
            }
            mem[indices] = new UF(mem[indices & ~(1 << index)]);
            for (int l = 0; l < 63; l++) {
                if ((nums[index] & (1l << l)) == 0) {
                    continue;
                }
                for (int h = l + 1; h < 64; h++) {
                    if ((nums[index] & (1l << h)) > 0) {
                        mem[indices].union(l, h);
                    }
                }
            }
            //System.out.println("sum = " + mem[indices].components);
            result.sum += mem[indices].components;
            return;
        }
        // no add
        generateAndAdd(i + 1, n, nums, indices, mem, result);
        // with add
        indices |= (1 << i);
        generateAndAdd(i + 1, n, nums, indices, mem, result);
        indices &= ~(1 << i);
    }
    
    private static class Result {
        private int sum = 0;
    }

    private static class UF {
        int[] uf;
        int[] size;
        int n;
        int components;
        private UF(int n) {
            this.n = n;
            uf = new int[n];
            size = new int[n];
            components = n;
            for (int i = 0; i < n; i++) {
                uf[i] = i;
                size[i] = 1;
            }
        }
        private UF(UF other) {
            this.n = other.n;
            uf = new int[this.n];
            size = new int[this.n];
            components = other.components;
            for (int i = 0; i < this.n; i++) {
                uf[i] = other.uf[i];
                size[i] = other.size[i];
            }
        }
        private boolean union(int i, int j) {
            int iRoot = root(i);
            int jRoot = root(j);
            if (iRoot == jRoot) {
                return false;
            }
            components--;
            if (size[iRoot] <= size[jRoot]) {
                uf[iRoot] = jRoot;
                size[jRoot] += size[iRoot];
            } else {
                uf[jRoot] = iRoot;
                size[iRoot] += size[jRoot];
            }
            return true;
        }
        private int root(int i) {
            while (uf[i] != i) {
                i = uf[i];
            }
            return i;
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int dCount = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long[] d = new long[dCount];

        String[] dItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < dCount; i++) {
            long dItem = Long.parseLong(dItems[i]);
            d[i] = dItem;
        }

        int components = findConnectedComponents(d);

        bufferedWriter.write(String.valueOf(components));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
