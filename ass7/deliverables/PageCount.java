R. Hayden Anderson
CS440
Assignment 7


import java.io.IOException;
import java.util.*;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class PageCount{
	
	public static class TokenizerMapper
		extends Mapper<Object, Text, Text, IntWritable>{
		private final static IntWritable one = new IntWritable(1);
			
		@Override
		public void map(Object key, Text value, Context output) throws IOException, InterruptedException {
			String[] words = value.toString().split(" ");
 				

			if (words[words.length - 1].equals("T")){
				IntWritable amount = new IntWritable(Integer.parseInt(words[1]));
				output.write(new Text(words[0]), amount);
				
			}

		}
	}

	public static class IntSumReducer
		extends Reducer<Text,IntWritable,Text,IntWritable> {
			private IntWritable result = new IntWritable(1);
		
			@Override
			public void reduce(Text key, Iterable<IntWritable> values,
					Context output
					) throws IOException, InterruptedException {
				int voteCount = 0;
				for (IntWritable value: values){
					voteCount+= value.get();
				}
				output.write(key, new IntWritable(voteCount));
			}
		}


	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();
	
		Job job = Job.getInstance(conf, "page count");
		job.setJarByClass(PageCount.class);
		job.setMapperClass(TokenizerMapper.class);
		
		job.setCombinerClass(IntSumReducer.class);
		job.setReducerClass(IntSumReducer.class);
		
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);
		
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(args[1]));

		System.exit(job.waitForCompletion(true) ? 0 : 1);
		
		
	}

	
	
}

